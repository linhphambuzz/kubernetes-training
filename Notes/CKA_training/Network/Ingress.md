- Ingress helps to access application using external configured URL -> route traffics to different services with SSL functionalities. 
- Is layer 7's load balancer that can be configured using K8s's primitives 
- Ingress needs to be exposed to be visible outside the cluster : either published it as a `nodeport `or via cloud provider. This is a one-time configuration. All of the configuration later on for services will use `Ingress-Controller`

## Ingress in Kubernetes cluster 
1. Deploy any solution: HAProxy, Nginx, Traefik -> `ingress-controller`
2. Specify a set of rule to configure the ingress ->`ingress-resources`
	1.  Ingress resources are created using definition files

## INGRESS CONTROLLER 
- This lectures mention about **NGINX** specifically 
1. Deployment 
![](../../../img/Pasted%20image%2020250526115651.png)
2. ConfigMap: 
	1. decouple setting for error, keep-alive, and ssl option 
	2. could be blank initially, will modify later
3. `.spec.env` : NGINX service requires these to read the config data from within the pod
	1. POD_NAME
	2. NAME_SPACE 

4. Specifiy ports used by the controller 
![](../../../img/Pasted%20image%2020250526120033.png)

5. Service for the ingress controller 
![](../../../img/Pasted%20image%2020250526120338.png)

6. Service Account with Roles, ClusterRoles and RoleBinding for **Authentication** 


![](../../../img/Pasted%20image%2020250526120618.png)

## INGRESS RESOURCES 
1. Same host, different path 
 ![](../../../img/Pasted%20image%2020250526123753.png)
- [Errata for apiversion,servicename, and serviceport ](https://www.udemy.com/course/certified-kubernetes-administrator-with-practice-tests/learn/lecture/28046886#overview)

2. Different host 
![](../../../img/Pasted%20image%2020250526173757.png)
## Rewrite target 
- [Article](https://www.udemy.com/course/certified-kubernetes-administrator-with-practice-tests/learn/lecture/16827080#overview)
>[!Note] This link is specific for NGINX