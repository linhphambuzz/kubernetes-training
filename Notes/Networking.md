## Pod

- IP address is assigned to pod 
- IP address is changed when pod is recreated
## Cluster Networking

- Kubernetes doesn't automatically set up so that pods are assigned different IP addresses
- Fundamental rules: 
1. All the containers or PODs in a kubernetes cluster MUST be able to communicate with one another without having to configure NAT.
--> solutions available in the industry. 


## Services 

Kubernetes Services enable communication between various components within and
outside of the application. Kubernetes Services helps us connect applications
together with other applications or users. 


### Nodeport service

- listen to a port on the Node and forward requests on that port to a port on the POD running the web application.
- NodePort is the service makes an internal POD accessible on a Port on the Node.
- Port on pod: target pod
- Port on service. The service is in fact like a virtual server inside the node. Inside the cluster it has its own IP address. And that IP address is called the Cluster-IP of the service
- port on the Node itself which we use to access the web server externally. NodePorts can only be in a valid range which is from 30000 to 32767.
### Cluster IP

- The service creates a virtual IP inside the cluster to enable communication between different services. 

### Load balancer 


## Service file definition 

![[Pasted image 20240622105553.png]]

To link the service to the pod, bring the `labels` section of `pod-definition.yaml` to `selector`



