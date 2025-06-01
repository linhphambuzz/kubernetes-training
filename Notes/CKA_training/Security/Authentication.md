## Kube-apiserver 
- Authenticate user
- Process req 
- Authentication mechanisms: static pw file, static token file, certificates, identity services
## Basic Auth (deprecated)
[References](https://www.udemy.com/course/certified-kubernetes-administrator-with-practice-tests/learn/lecture/14296208#overview)
1. Static password file 
- create a csv file with password, usrname, uid
- pass the csv file to `--basic-auth-file` to kube-apiserver
- restart the kube-apiserver
![](../../../img/Pasted%20image%2020250526211421.png)
- To authenticate: 
```bash
	curl -v -k https://master-node-ip:6443/api/v1/pods -u "user1:password123"
```

2. Static Token file
![](../../../img/Pasted%20image%2020250526211748.png)

>[!Note]
>These are not recommended authentication mechanism because they're not secure