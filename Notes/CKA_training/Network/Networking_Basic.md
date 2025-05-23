
## Switching 
![](../../../img/Pasted%20image%2020250516165724.png)
- Each host has `eth0` as interface to connect to the switch 
- `ip link` : to see interfaces on the host. 
- `ip addr add` is used to add the ip adresses range of the switch to the host, used to add an IP address to a network interface (i.e: `eth0`)
- After this, A and B can talk to each other thru the switch 
- Switch can only enable communication within a network

## Routing 
- How does system in one network connected to another network? 
- Help connected 2 networks together: it assigns 2 separate ip addresses(i.e.: 192.168.1.1 and 192.168.2.1) for each network that it help connecting together. 

## Gateway 
![](../../../img/Pasted%20image%2020250517110200.png)
- How does `B` know about `C` to send a packet to it? 
- Gateway: door to the world to the network
- To see the existing routing algorithm on a host: `route` cmd --> display kernel's routing table
- To configure a gateway on system B: `ip route add 192.168.2.0/24 via 192.168.1.1`
- To configure a gateway on system C: `ip route add 192.168.1.0/24 via 192.168.2.1`
- To get out to the internet: `ip route add 172.217.194.0 via 192.168.1.1 
### Default gateway 
- It's time consuming to add every network config for each of the ip addresses in the internet. 
- Default gateway: any routing that you don't know the route to, use the router's ip : `ip route add default via 192.168.2.1`
- `0.0.0.0` is equivalent to `default`
- If the gateway is set to `0.0.0.0`: the host communicates with components within each own network

![](../../../img/Pasted%20image%2020250518111814.png)
- Multiple routers can be used: one for internal network, one for going out to the internet : 192.168.2.1 is for the internet, 192.168.2.2 is for internal
![](../../../img/Pasted%20image%2020250518112209.png)

## Linux host as a router

1. Adding routing rule: 
- on A: ip route add 192.168.2.0/24 via 192.168.1.6
- on C: p route add 192.168.1.0/24 via 192.168.2.6
-> After this step, A and C can ping, but there's nothing show up. 
- Linux disable packets forwarding by default 


1.  Enable packet fowarding 
- `cat /proc/sys/net/ipv4/ip_forward` : default is 0 
- set it to 1 ->  enabled 
- the change isn't persistent 
- to make it persistent: `/etc/sysctl.conf`

 