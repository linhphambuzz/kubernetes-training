- `/version`: purview the version of the API 
- `/metrics` & `/healthz`: monitor health  for the cluster
- `/log`: integrate with logging 
## CORE (/api)
![](../../../img/Pasted%20image%2020250608182744.png)

`curl http://locahost:6333 -k --key admin.key --cert admin.crt --cacert ca.crt`
- An alternate way to authenticate using kubectl is to use `kubectl proxy` (at pot 8001)-> this will use the client certifcate in the kubeconfig file 
## Named (/apis)
![](../../../img/Pasted%20image%2020250608182902.png)

`curl http://locahost:6333/apis -k | grep "name"`

