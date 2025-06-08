## Certificates
1. Server cert: configured on the server
2. Client cert: configured by client 
3. Root cert: configured by CA server 
>[!Note] 
>Private key have `key` in them

## Server Certificate
- **Kube-api serve**r: crt and key, exposes https api service
- **ETCD server**: crt and key 
- **Kubelet server**: on worker node, exposes an https api that the kube-api server talks to
![](../../../img/Pasted%20image%2020250604184507.png)
## Client Certificate 
- **Admin:** needs crt and key pair to authenticate to the kube-api server
- **Kube-Scheduler**: is client to kube-api server. It talks to kube-api server to look for pods that need scheduling .
- **Kube-Controller-Manager**: is also a client to kube-api server
- **Kube-proxy**: also a client to kube-api server
- **Kube-api-server:** is the only client to the ETCD server
- **Kube-api-serve**r: also talk to kubelet on each individual node. That's how it monitors the worker's node. 
![](../../../img/Pasted%20image%2020250604185914.png)

## CA 
- You're required to have at least one CA for your cluster
- There could be one CA for ETCD, one for the rest of the cluster
![](../../../img/Pasted%20image%2020250604190207.png)

## Certificate Creation 
### Certificate Authority (CA)
1. Generate keys 
```bash
openssl genrsa -out ca.key 2048 --> this will give ca.key
```
2. Certificate Signing Request: all signing details w/o signatures
```bash
openssl req -new -key ca.key -subj "CN=KUBERNETES-CA" -out ca.csr 
```
3. Sign certificates
```bash
openssl x509 -req -in ca.csr -signkey ca.key -out ca.crt
```

### Client Certificate 

Same procedure, the only difference is when doing Sign Certificates, you specify CA cert and CA key 
![](../../../img/Pasted%20image%2020250607161041.png)

#### Kube Scheduler

![](../../../img/Pasted%20image%2020250607161308.png)

#### Kube-Controller-Manager 

![](../../../img/Pasted%20image%2020250607161346.png)

#### Kube-proxy: similar to controller mnger and admin

>[!Note] 
>For client to be able to be verified using certificates, all components of the cluster needs a copy of the public cert of the CA
#### Kubelet (being client talking to kubeapi-server)
- Same with system's component: name starts with `system:node
![](../../../Pasted%20image%2020250607170812.png)`
### Server Certificate 
#### ETCD server 
- Besides being a server, they also need peer server for HA 
- Key, Crt, and trusted-ca-file (public root cert.) must be specified 
![](../../../img/Pasted%20image%2020250607162752.png)

#### kube api server

-  All the aliases must be configured in the cert by passing in `-config openssl.conf` in generating certificate signing request 
```bash
openssl req -new -key apiserver.key -subj "CN=kube-apiserver" -out apiserver.csr\
-config openssl.cnf
```
![](../../Pasted%20image%2020250607163241.png)
- Finally, sign the cert: 
```bash
openssl x509 -req -in apiserver.csr \
-CA ca.crt -CAkey ca.key -out apisever.crt
```
- In the executable used to configure kube-apiserver service configuration file :  
	- acting as client to communicate with kubelet and etcd: ca file, crt, key 
	- as server: ca file, cert and key
![](../../../img/Pasted%20image%2020250607170138.png)

#### kubelet server
- https server that runs on each node, responsible for managing the node
- Each node should have its own kube-let.config with the ca file, the certificate, and the key
![](../../../img/Pasted%20image%2020250607170412.png)
## How to use  cert? 

1. To authenticate with kube-api server 

```bash 
curl https://kube-apiserver:6443/api/v1/pods \ 
--key admin.key  --cert admin.crt --cacert ca.crt
```

2. Use them in `kube-config.yaml`

## View Cert 

```bash 
openssl x509 in /etc/kubernetes/pki/apiserver.crt -text -noout
```

![](../../../img/Pasted%20image%2020250607171928.png)

### Healthcheck
- Using journalctl :`journalctl -u etcd.service -l`
- `kubectl log etcd-master`
- When kube-api-server and kubelet is down, follow procedure to check docker container 


