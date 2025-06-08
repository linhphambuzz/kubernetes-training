## CA 
- anyone with access to key-pair of CA can authenticate anything on the cluster
- .pem and .key need to be secured 
- kubeadm creates ca pair on master node 
- as team growth, to manage cert: needs automation 

## Certificate api 
- instead of logging on the master node where key pair is kept, an object of type `CertificateSiginingRequest` is created. The req is then review and approve using `kubectl`. The cert is then shared with users 
1. Create a  key 
```bash 
openssl genrsa -out jane.key 2048 
```
2. Send CSR request to admin 
```bash
openssl req -new -key jane.key -subj "CN=KUBERNETES-CA" -out jane.csr
```
- CSR object is then created using .yaml manifest. The `jane.csr` must first be `base64` encoded before putting in the manifest 

![](../../../img/Pasted%20image%2020250608120516.png)
3. To approve the request : `kubectl certificate approve jane`
4. View certificate : `kubectl get csr jane -o yaml` (under{.status.certificate}) base64 encoded 00> share w user

>[!Important] 
>Controller Manager is the component taking care of these certificate api 
> - CSR approving/ signing, etc.

- `kube-controller-manager`'s manifest must have root's cert and key 
![](../../../img/Pasted%20image%2020250608120909.png)