- Drain the node of all the workload so pods that belong to RS can be moved to other nodes. When node is drained, the pods will be gracefully terminated. Node will also be marked as Unscheduleable
```bash
kubectl drain node1
```
- To make node schedulable again:
```
kubectl uncordon node
```
- To make new pods not schedule on a node
```
kubectl cordon node
```
