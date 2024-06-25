##  Container 
- Operating systems: OS kernels and set of software 
- Docker container share the underlying kernel: Dokcer can run any OS flavor on top of it, as long as they're in same kernel 
- Docker utilizes the underlying kernel of Docker host 
- Docker can't run another kernel on the OS (can't run window on  a Linux machine)
- ![[20240619150509.png]]![[20240619150534.png]]


### Images vs. Container
- Image: template 
- Container: running instances of images

## Container orchestration

### Kubernetes Advantages 

- Applications are run on different nodes -> no down time 
- When in demand --> deploying and load balancing seamlessly 
- It is a container Orchestration technology used to orchestrate the deployment and management of 100s and 1000s of containers in a clustered environment.


### Kubernetes Architectures 

1. Nodes 
- A node is a machine – physical or virtual – on which kubernetes is installed. A node is a worker machine and this is were containers will be launched by kubernetes. 
2. Cluster 
- A set of nodes group together 
3. Mater 
- The master is another node
with Kubernetes installed in it, and is configured as a Master.
- watches
over the nodes in the cluster and is responsible for the actual orchestration of
containers on the worker nodes.

### Components 
![[20240619180557.png]]

1. API server: acts as the front-end for kubernetes. The users, management devices,
Command line interfaces all talk to the API server to interact with the kubernetes
cluster.

2. ETCD: distributed reliable key-value store used by kubernetes to store all data used to manage the cluster. 
- Etcd stores all that information on all the nodes in the cluster in a distributed manner
- ETCD is responsible for implementing locks within the cluster to ensure there are no conflicts between the Masters
3. The scheduler is responsible for distributing work or containers across multiple nodes. It looks for newly created containers and assigns them to Nodes.
4. The controllers are the brain behind orchestration. They are responsible for noticing and responding when nodes, containers or endpoints goes down 
5. The container runtime is the underlying software that is used to run containers (i.e:DOCKER)
6. kubelet is the agent that runs on each node in the cluster. The agent is responsible for making sure that the containers are running on the nodes as expected.

### Master vs Worker Nodes 


| Mater                  | Worker                                        |
| ---------------------- | --------------------------------------------- |
| has the kube-apiserver | where the containers (e.g: Docker) are hosted |
| ETCD is stored here    |                                               |
| Controller             |                                               |
| Scheduler              |                                               |


### kubectl 

- use to deploy and manage cluster 
- To deploy an application on the cluster 
`kubectl run hello-minikube `
- To view information about the cluster
`kubectl cluster info`
- List all nodes part of the cluster 
`kubectl get nodes `

## Docker vs Containerd

1. Open Container initiative (OCI) for Container Runtime Interface 
- imagespec: standard on how image should be built
- runtimespec: how container should be built 
2. Dockershim is born to support Docker runtime as it doens't adhere with OCI 
3.  Containerd is designed to work as CRI 

### Containerd

- `ctr` can be used to only debugging, not user-friendly 
- `nerdctl` provides Docker-like CLI for containerD
- `crictk` provides a CLI for CRI compatible container runtimes

![[20240619190823.png]]