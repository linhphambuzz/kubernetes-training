## Typical logs' locations 
- `/var/log/pods`
- `/var/log/containers`
- `crictl ps` + `crictl logs`
- `docker ps` + `docker logs` (in case when Docker is used)
- kubelet logs: `/var/log/syslog` or `journalctl`

>[!Note]
> If kube-api is down, check` /var/log/containers` as the kube-api container will restart and might have some useful error logs.
## Useful info 

- List all processes to examine kube-system component: 
```bash
ps aux | grep kube-system 
```