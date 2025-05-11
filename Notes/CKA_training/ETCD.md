## Definition 
- Distributed key-value storage
## Install 
![](../../img/Pasted%20image%2020250415024814.png)
- etcd is typically set up to listen on port 2379 

>[!Source] 
>https://www.udemy.com/course/certified-kubernetes-administrator-with-practice-tests/learn/lecture/19537454#overview

-  You must also specify path to certificate files so that ETCDCTL can authenticate to the ETCD API Server. The certificate files are available in the etcd-master at the following path :

```bash
1. --cacert /etc/kubernetes/pki/etcd/ca.crt
2. --cert /etc/kubernetes/pki/etcd/server.crt
3. --key /etc/kubernetes/pki/etcd/server.key
```

- Example: 
```bash
kubectl exec etcd-master -n kube-system -- sh -c "ETCDCTL_API=3 etcdctl get / --prefix --keys-only --limit=10 --cacert /etc/kubernetes/pki/etcd/ca.crt --cert /etc/kubernetes/pki/etcd/server.crt --key /etc/kubernetes/pki/etcd/server.key"
```

## ETCD's manifest specific 

```bash 
--listen-peer-urls=https://172.30.1.2:2380
```
- List of URLs to listen on for peer traffic.
- Default: `http://localhost:2380` 
- env variable: `ETCD_LISTEN_PEER_URLS`
```bash 
--listen-client-urls=https://127.0.0.1:2379,https://172.30.1.2:2379
```
- List of URLs to listen on for client traffic. This flag tells the etcd to accept incoming requests from the clients on the specified scheme
- Default: “http://localhost:2379”
- env variable: `ETCD_LISTEN_CLIENT_URLS`
- example: “http://10.0.0.1:2379”
- invalid example: “[http://example.com:2379](http://example.com:2379/)” (domain name is invalid for binding)
 >[!Important]
>** kube-api talks to etcd using listen-client-urls** 
```bash 
--listen-metrics-urls=http://127.0.0.1:2381
```
- useful for healthcheck, also respond to `/health` endpoint.  
- the `/livez` endpoint reflects whether the process is alive or if it needs a restart.
- the `/readyz` endpoint reflects whether the process is ready to serve traffic.

