## Main duty 

![](../../../img/Pasted%20image%2020250511135113.png)

## Examples
### Node Controller
- takes status of Node via kube-apiserver every 5 secs to monitor health of node. Grace period is 40s before a node is marked unreachable 
- ![](../../img/Pasted%20image%2020250511135323.png)

### Replication Controller 

- Watch out for numbers of replica within a replica set and make sure it meets the desire replicas. 

### Controller varieties 

![](../../img/Pasted%20image%2020250511135551.png)

- A lot of components within the K8s cluster are implemented using controller

## Kube-Controller-Manager 

### Installing 

![](../../img/Pasted%20image%2020250511135817.png)
- Different types of controllers can be enabled by admin.

>[!Note]
> controller-manager-options can be viewed under: 
> - `etc/systemd/system/kube-controller-manager.service`
> - `ps -aux | grep kube-controller-manager`