- Point of contact from master node to worker node
- load/unload container to their node  as instructed by scheduler 
- send back report at reg. interval for nodes and containers

## Main Duty 
- it commands the container runtime (i,e: Docker) to start container as instructed by the scheduler.
- it monitors state of pod & container and report to api-server 

![](../../img/Pasted%20image%2020250511143156.png)

## Installing 

![](../../img/Pasted%20image%2020250511143311.png)
- Must be installed manually on each worker 
- must be tls bootstrap 

## Helpful Troubleshooting Command 
- To query kubelet's status 

```bash
	systemctl status kubelet
```
- To restart:
```bash
	systemctl restart kubelet
```
- Using journalctl 
```bash
journalctl -e -u kubelet
```


- If query node's health using kubectl isn't returned, most likely the problem is from the `kubelet`
- Steps to troubleshoot: 
	- ssh into the node
	- `crictl ps` to see what containers are up
	- journalctl and /var/log/syslog for logs
	- query all config files(i.e: ps aux| grep should show mostly everything) : etc/kubernetes/kubelet.conf, /var/lib/kubelet/config.yaml

## Resource 

- [Kubelet Config File](https://kubernetes.io/docs/tasks/administer-cluster/kubelet-config-file/)
- [Configure Cluster using Kubeadm](https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/kubelet-integration/)