- Service are on all node :cluster-wide abstract 
## kubelet

-  watches the changes in the cluster using `kube-apiserver` to create pods on the nodes
- invokes CNI to create network for that pod
## kubeproxy 
- watches the changes in the cluster using `kube-apiserver`, if new service is to be created, it gets into action 
- When svc is created, it gets an ip addr from a pre-defined range, kubeproxy gets the ip address then create the forwarding rule on each node
- The fowarding rule specifies that any traffic that goes to the service's ip should go to the ip of the pod
![](../../../img/Pasted%20image%2020250526092739.png)
- Rules: set by `kube-proxy --proxy-mode [option]`
	1. `userspace`: kubeproxy listens on a port for each service and proxy connection to the pod 
	2. `ipvs` rule
	3. `iptables` (default)

- To search for NAT rule of a particular service 
```bash
	iptables -L -t nat | grep <svc-name>
```
- Service should show to be routed to pod's ip
![](../../../img/Pasted%20image%2020250526093237.png)
- Check `kubeproxy.log` :
```bash 
	cat /var/log/kube-proxy.log
```

