## Horizontal Autoscaling
- Adding more instances
### The manual way
```bash
kubectl scale deployment my-app --replica=3
```
### Using HPA 
#### Imperative 

![](../../../img/Pasted%20image%2020250621160835.png)

#### Declarative 

```bash
apiVersion: autoscaling/v2
kind: HorizontalPodAutoscaler
metadata:
  name: php-apache
spec:
  scaleTargetRef:
    apiVersion: apps/v1
    kind: Deployment
    name: php-apache
  minReplicas: 1
  maxReplicas: 10
  metrics:
  - type: Resource
    resource:
      name: cpu
      target:
        type: Utilization
        averageUtilization: 50
status:
  observedGeneration: 1
  lastScaleTime: <some-time>
  currentReplicas: 1
  desiredReplicas: 1
  currentMetrics:
  - type: Resource
    resource:
      name: cpu
      current:
        averageUtilization: 0
        averageValue: 0

```
## Vertical Autoscaling 
- Adding more resources to your existing applications 

## Scaling Cluster Infra 
- Horizontal: adding more nodes to the cluster
- Vertical scaling: adding resources to the existing nodes in the cluster
## Scaling Workloads
-  horiz: getting more pods
-  vertical: adding resources to the existing pods
![](../../../img/Pasted%20image%2020250621160254.png)


## Metrics 
- Custom Metric Adapter: can be used to get workload's metrics
- ![](../../../img/Pasted%20image%2020250621161450.png)

## In-place resize of Pod Resources
- Still under beta phase (1.33 version)
- To use this: set `FEATURE_GATES=InPlacePodVerticalScaling=true`
- With this option enabled, the change in resize request won't kill the pod
```bash 
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deployment
  labels:
    app: nginx
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:1.14.2
        ports:
        - containerPort: 80
        resizePolicy:
        - resourceName: cpu
          restartPolicy: NotRequired
        - resourceName: memory 
          restartPolicy: RestartContainer <-----memory can't be adjusted dynamicaly
        resources: 
          requests:
            cpu: "1"
            memory: "256Mi"
          limits:
            cpu: "500m"
            memory: "512Mi" 

```

![](../../../img/Pasted%20image%2020250622124548.png)
[References](https://kubernetes.io/docs/tasks/configure-pod-container/resize-container-resources/)