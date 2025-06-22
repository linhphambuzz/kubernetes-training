## Deploymemt strategy
1. Recreate
2. Rolling update:default 
## Upgrades
- new ReplicaSet is created with same amount of pods as the old replicaset 

## Rollback

```bash 
kubectl rollout undo deployment/name
```