- To make use of `**etcdctl**` for tasks such as backup, verify it is running on API version 3.x:

```bash
etcdctl version
```

## Snapshot Based backup  

```bash
ETCDCTL_API=3 etcdctl 
 --endpoints=https://127.0,0,1:2379
 --ca-cert=/etc/kubernetes/pki/etcd/ca.crt \
 --cert=/etc/kubernetes/pki/etcd/server.crt \
 --key=/etc/kubernetes/pki/etcd/server.key \
 snapshot save /backup/etcd-snapshot.db
```

- **--endpoints** points to the etcd server (default: localhost:2379)
    
- **--cacert** path to the CA cert
    
- **--cert** path to the client cert
    
- **--key** path to the client key


## File Based Backup

```bash 
 etcdutl backup \
  --data-dir /var/lib/etcd \
  --backup-dir /backup/etcd-backup
```
- This copies the etcd backend database and WAL files to the target location.
-  Performs a raw file-level copy of etcd’s data and WAL files without needing etcd to be running.

##  Checking Snapshot Status

```bash
etcdctl snapshot status /backup/etcd-snapshot.db --write-out=table
```

- This shows details like size, revision, hash, total keys, etc. It is helpful to verify snapshot integrity before restore.
## Restoring ETCD
- To restore a snapshot to a new data directory:
```bash
 etcdutl snapshot restore /backup/etcd-snapshot.db \
 --data-dir /var/lib/etcd-restored
```
- is used to restore a **.db** snapshot file.
- To use a backup made with **etcdutl backup**, simply copy the backup contents back into **/var/lib/etcd** and restart etcd.

## References

- [K8S Docs](https://kubernetes.io/docs/tasks/administer-cluster/configure-upgrade-etcd/#backing-up-an-etcd-cluster)