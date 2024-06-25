1. Dictionaries 
2. List 
3. List of dictionaries 

Kubernetes uses YAML files as input for the creation of objects such as PODs, Replicas, Deployments, Services etc. 

4 top level fields for a kuberrnetes definition file: 
-  apiVersion: This is the version of the kubernetes API we’re using to create the object.
-  kind: type of obj. we're trying to create 

| Kind       | Version |
| ---------- | ------- |
| POD        | v1      |
| Service    | v1      |
| ReplicaSet | apps/v1 |
| Deployment | apps/v1 |

-  metadata :metadata is data about the object like its name, labels etc. Under labels you CAN have any kind of key or value pairs as you see fit
-  spec: provide info about the object 

```
apiVersion: v1 
kind: Pod 
metadata: 
	name: myapp-pod
	labels:
		app: myapp 
		type: front-end 

spec: 
	containers:
		- name: nginx-container
		  image: nginx
```


After this, enter : 

`kubectl create -f pod-definition.yml` 

to create the pod

![[20240620133954.png]]


### Demo

