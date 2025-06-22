## Limitation for ingress
- multi-tenancy
- namespace isolation 
- no RBAC for features
- For instance: 2 backend services are managed by 2 different teams having to share the same ingress resources 
![](../../../img/Pasted%20image%2020250526174046.png)

- Specific config are specified using annotations that are specific to the ingress controller
![](../../../img/Pasted%20image%2020250526174229.png)


## Definition 
- Official Kubernetes project focuses on layer 4(i.e: transport layer) and layer 7(i.e: application layer)
- represents next genarations of ingress, load balancing, and service mesh APIs
## Roles 
- Infrastructure provider: set up gateway class, define what the underlying network infrastructure would be. Such as nginx, traefik, other LB 
- cluster operators: instance of the gateway class
- application dev:  the http route, tcproute, grpcroute, and others  

![](../../../img/Pasted%20image%2020250526175407.png)

## Ingress vs Gateway API
- In Gateway API, the protocol is more declarive, tls config and route kind are more explicit, 
![](../../../img/Pasted%20image%2020250526180111.png)

- Canary deployment:
![](../../../img/Pasted%20image%2020250526180820.png)