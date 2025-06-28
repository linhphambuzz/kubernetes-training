## Upgrading master node's components 
- `kube-api-server` should be the one with the highest version number
- `kube-scheduler`,`etcd`,`kube-controller-manager`,`kubelet` should not have a higher version than `kube-api-server`
- `kubectl` can be higher
![](../../../img/Pasted%20image%2020250625185054.png)
- At the time, kubernestes support 3 minor versions at a time. 
- To upgrade from 1 version to another, do it one version at a time: 1.10 -> 1.11 -> 1.12
## Master
- When master is down, all manage function is down (can't use kubectl, pods can't be recreated,etc.). However, all applications should still function as normal 
## Worker
- Upgrade all at once: all apps are down --> downtime
- Upgrade one node at a time: move pods from one pod to another and so on. 
- Join in a new node: simply remove the old node with the new node 
## Kubeadm upgrade

### Mater Node
```bash
kubeadm upgrade plan
apt-get upgrade kubeadm=1.x.x
kubeadm upgrade apply v1.x.x
apt-get upgrade kubelet=1.x.x
```
- kubelet has to be updated manually
- we have to upgrade kubeadm itself before anything else
>[!Note] The output of `kubectl get node -o wide` command shows the version of the kubelet that registers at each node, not of the actual version of the API server itself

- When everything is upgraded, restart the kubelet service by:
```bash
systemctl restart kubelet
```

### Worker Node

```bash
kubectl drain node01
apt-get upgrade kubeadm=1.x.x
apt-get upgrade kubelet=1.x.x
kubeadm upgrade node config --kubelet-version v1.x.x
systemctl restart kubelet
kubectl uncordon node01

```