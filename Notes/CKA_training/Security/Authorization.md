## Authorization Mechanism 
1. Mechanism 
	- Node
	- ABC
	- RBAC
	- Webhook
	- AlwaysAllow
	- AlwaysDeny
2. Within the exec binary of the service, authorization mechanism is set in the `--authorization-mode`, is default to AlwaysAllow
![](../../../img/Pasted%20image%2020250608193347.png)
3. Authorization mode can be set using chain of mechanism
## Node 
- Kubelet accesses kube-api server to read information about the services, endpoints, nodes and pods. The Kubelet also give kube-api server information about the node
- These req are handled by **Node Authorizer**
- All req coming from the group with prefix `system:node`
## Atribute Based Authorization Access Control 
- User or group of users with a set of permission. 
- [References](https://kubernetes.io/docs/reference/access-authn-authz/abac/)
- Difficult to manage: any change needs to edit the policy manually -> restart kube-apiserver
![](../../../img/Pasted%20image%2020250608190621.png)

## RBAC 

- Creare role with set of permission, then bind users to it 

## Webhook 
- Granted access based on third-party agent