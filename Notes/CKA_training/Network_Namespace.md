
## Process Namespace 
- Each docker container can only see resources within the process namespace
![](../../img/Pasted%20image%2020250521130006.png)

## Network Namespace 
- Host has its own interface to connect to LAN, along with ARP and Routing Table 
- Within the container, the samething above applied
![](../../img/Pasted%20image%2020250521130254.png)

#### Create network namespace 
- `ip netns add <name-net-space>`: to add
- `ip netns`: to list 
#### Exec in network namespace 
![](../../img/Pasted%20image%2020250521130829.png)
- On host: lo and eth0 is listed, but inside `red` network namespace, only lo is listed. This is because it's in an isolated environment. 
- The same thing is applied to `arp` (i.e address resolution protocol) command.

#### Connect two interfaces 
![](../../img/Pasted%20image%2020250521133306.png)

1. Make the connection
	- The **veth** devices are virtual Ethernet devices
	- Add `veth-blue` interface and `veth-red` together 
	```bash
	ip link add veth-blue type veth peer name veth-red
	```

	- The generic syntax would be: 
	```bash
	ip link add <p1-name> netns <p1-ns> type veth peer <p2-name> netns <p2-ns>
	```

2. Attach interfaces to the namespace they belong to 
```bash
	ip link set veth-red net-ns red	
	ip link set veth-blue net-ns blue	
```

3. Set ip addresses to each network interface
	- In `red` ns:  .15.1 is its ip with `veth-red` interface
	- In `blue` ns:  .15.2 is its ip with `veth-blue` interface
```bash
	ip -n red addr add 198.168.15.1 dev veth-red
	ip -n blue addr add 198.168.15.2 dev veth-blue 
```
4. Bring the interfaces up 
```bash 
	ip -n red link set veth-red up
	ip -n blue link set veth-blue up
```

### Virtual Network Switch
- To enable comunication between network namespaces. Popular products are
  : Linux Bridge, OpenVSwitch 
#### Linux Bridge Demo
1. Add an interface of type `bridge` to host : `ip link add v-net-0 type bridge`
2. Bring the virtual switch's interface up: `ip link set dev v-net-0 up`
3.  Connecting interfaces
```bash
ip link add veth-red type veth peer name veth-red-br
ip link add veth-blue type veth peer name veth-blue-br
...
```

4. Bring one end of the interface to the namespace, the other end to the virtual switch
```bash
ip link set veth-red netns red
ip link set veth-red-br master v-net-0
```

>[!Note]  
>`ip link set`, when used with `master`, it associates a network device (like a virtual interface) with a bridge, effectively adding it to the bridge

5. Add ip adresses associate with each network interface
```bash
ip -n red addr add 192.168.15.1 dev veth-red
ip -n blue addr add 192.168.15.2 dev veth-blue
```

6. Bring the interfaces up 
```bash 
ip -n red link set veth-red up
ip -n blue link set veth-blue up
```

>[!Important]
> The network that contains `veth-red`, `veth-blue` and `v-net-0` for the virtual switch are isolated. That is, if the host try to ping one of the namespaces, it's not reachable
> Nothing from the outside world can reach this namespace and vice versa

- For host ping to one of the namesapces connected to the virtual switch to work, assign `v-net-0` with an ip adress
```bash
ip addr add 192.168.15.5/24 dev v-net-0
```

#### NAT 
- On the host: 
	- `eth0` is the interface to the external network
	- `v-net-0` is the interface for the virtual network switch of all the namespaces (i.e: red-veth, blue-veth,etc.)
- If a namespace connected using v-net-0 bridge network want to send a package to another host in the outside world, we need to add NAT rule to the iptables. This masquerade/replace the from-address (i.e:  specifc ip of namespace), making sure that other hosts outside would think any packet sent is from the host itself, and not from within the namespaces
```
iptables -t nat -A POSTROUTING -s 192.168.15.0/24 -j MASQUERADE

```
- Add destination ip to routing table of the network namespace: 
```bash
ip netns exec blue ip route add 192.168.1.0/24 via 192.168.15.5
```
>[!Reminder] `192.168.15.5` is the ip address assigned to `v-net-0` interface


![](../../img/Pasted%20image%2020250521220435.png)

#### Connect to the internet

```bash
ip netns exec blue ping 8.8.8.8
```

- Since there's no route to 8.8.8.8, ping is unreachable
- To reach any external network, talk to the host:
```bash
ip route add default via 192.168.15.5
```

#### Hosts connect to network namespace 
- Portfowarding traffic from port 80 on host to port 80 of the network namespace 
```bash
iptables -t nat -A PREROUTING --dport 80 --to-destination 192.168.15.2:80 -j DNAT
```

![](../../img/Pasted%20image%2020250521221803.png)