- By default, `KUBECONFIG` is located at `~/.kube/config`
## Kubeconfig file
![](../../../img/Pasted%20image%2020250608145702.png)
### Clusters
- Clusters that you need access to 

### Users 
- User accnt that have access to these clusters 

### Context 
- define which user account is used to access which cluster
- can be set to use in a specific namespace 



## Certificate in Kubeconfig 
- under `clusters`, instead of using `certificate-authority` to specify the path to cert, use `certificate-authority-data`, encode the cert in base64