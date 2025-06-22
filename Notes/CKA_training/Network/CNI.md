## Intro
- Set of standard that defines how programs should be developed to solve networking challenges in cntainer runtime environment. 
- Bridge network is a pluggin for CNI 
- So long as these following set of rule are followed, cntainer runtimes and CNI works on harmony
![](../../../img/Pasted%20image%2020250522220736.png)

- Docker does't support CNI, it has its own thing (i.e:CNM)
- In Kubernetes: docker container is created with `none` network, then the container is added to the bridge network later on by the configured CNI plugins. 
![](../../../img/Pasted%20image%2020250522221251.png)

## CNI in Kubernetes 

1. Configuring plugging 
- Network plugging are all installed in `/opt/cni/bin` -> where cntainer runtime finds the plugging 
- Which pluggin to use and how to use it: `/etc/cni/net.d`
![](../../../img/Pasted%20image%2020250525121930.png)

>[!Note] 
> - `ipam.subnet` specifies range of ip for pods
> - `type`: can either be host-local or dhcp 


## CNI WEAVE 

- Agent is installed as service in each node: communicate with each other, exchanging info regardinng the node and netwrok of pods within the node they're 
- Each agent store topology for the setup of pods, ip on the other nodes 
- Weave creates its own bridge on each node, then it assigns ip address range to each nodes
>[!Note] A container can attach to diiferent bridge (i.e one created by Weave, another is the default from docker `docker0`) 

- Weave agent makes sure to encapsulate packet and decapsulate it appropriately so that packet can be transfered from one node to another 
#### IPAM (ip addr management)
- When a new container is created, veth pair is also created with one end attachs to the container's name space and the other to the bridge virtual network, the interface in the container's namespace also gets assigned an ip address.
- CNI comes with 2 built-in pluggin to help manage IP addr: 
	- `host-local`
	- `DHCP`
	- `cat /etc/cni/net.d/net-script.conf` :
		- under `ipam`: specify `type`, `subnet`, and `route`

- weave by default gives: `10.32.0.0/12`: `10.32.0.1` > `10.477.255.254`
- IP ranges will be splitted up evenly to nodes

## References
- [The Kubernetes Networking Guide](https://www.tkng.io/)
- [Slides from KubeCon 2018 about CNi](https://www.caseyc.net/cni-talk-kubecon-18.pdf)