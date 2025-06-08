- Detect new service, create appropriate forwarding rules to forwards traffic to svc to backend pods. For instance, using ip tables, each entry in the table : svc -> pod ip 
- kube-proxy (in kubeadm) is deployed using Daemonset
- Refer to Services note under Networking [Services](Network/Services.md)
## REFERENCES 
- [Kodekloud's blog post](https://kodekloud.com/blog/kube-proxy/)

