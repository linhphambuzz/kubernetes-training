
## Networking Model 
- Every pod should have an IP address
- Every pod should be able to talk to other pods within same node and other nodes as well (w/o NAT)

## Setting up cluster : 1 master + 2 workers (manual)
- GIven node 1: .1.11, node 2: .1.12, node 3: .1.13
- Each node: `ip link set v-net-0 type bridge && ip link set dev v-net-0 up `
- Set the ip address for the bridge interface, each bridge is on its own subnet: `ip addr add 10.224.1.1/24 dev v-net-0`
![](../../../img/Pasted%20image%2020250525120019.png)
- For each of the containers added into the node, run a script:
	- create veth pair
	- attach to ns
	- assign ip address, add route 
	- bring up the interfaces 

### Inter-node connection 

```bash
	$bluepod ping 10.244.2.2 # -> failed 
	$node1 ip route add 10.244.2.2 via 192.168.1.12 #(node2's ip)
```
- This gets complicated as more pods added. 
- Solution: doing via the router, points host to the router 
![](../../../img/Pasted%20image%2020250525120433.png)
- All bridge's subnet joined under 1 subnet: `10.244.1.0/24` -> `10.244.0.0/16`

## CNI 
- Helps  with all of the manual steps performed above 
- CNI contains: 
	- **Add** section: taking care of network associations with adding containers to the networks 
	- **Delete** section:  taking care of deleting network associations with deleting containers to the networks 
### Container runtime 
- Responsible for creating container 
- `/etc/cni/net.d/net-script.conflist` : identify plugin 
- `/opt/cni/bin/net-script.sh`: to find the script 
- `./net-script.sh add <cntainer> <namespace>` : script executed, adding container to the network namespace

>[!Tip]
>- `--service-cluster-ip-range=172.20.0.0/16` flag configured in the **kube-controller-manager** and **kube-api** is service's ip range
>- `--cluster-cidr` in `kubectl cluster-info dump` is pod's ip range