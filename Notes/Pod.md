


-  In worker's node, container is encapsulated in pod 
- Pod: is an instance of an application, smallest object in kubernetes 
- If there's an increasing in demands accessing the pod, another pod will be created  (i.e: 2 instances of applications running on 2 seperate pods )
- Pod has a 1:1 relationship with container 

### Multi-Container PODs
- A single pod can have multiple containers (typically not the same kind)
- An example is "helper container" 
- The 2 containers can also connect to each other by local host since they share the same network space 
- ![[20240619193230.png]]

### kubectl
1. To deploy an application 
`kubectl run nginx --image nginx`

- `--image` : to specify  images 

2. To get info about a specific pod 
`kubectl get pods`
`kubectl get pods -o wide`

3. Info about deployed pods
`kubectl describe pod <pod-name>`


### Pod References 

https://kubernetes.io/docs/concepts/workloads/pods/ 