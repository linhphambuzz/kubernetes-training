- Security configured in pod will carry to container 

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: security-context-demo
spec:
  securityContext: <--- at pod's level 
    runAsUser: 1000
    runAsGroup: 3000
    fsGroup: 2000
    supplementalGroups: [4000]
  volumes:
  - name: sec-ctx-vol
    emptyDir: {}
  containers:
  - name: sec-ctx-demo
    image: busybox:1.28
    command: [ "sh", "-c", "sleep 1h" ]

	volumeMounts:
	- name: sec-ctx-vol
	  mountPath: /data/demo
	securityContext:  <-- container's level
	  allowPrivilegeEscalation: false
	  ```yaml
		capabilities:
	        add: ["NET_ADMIN", "SYS_TIME"]
```
- container's capabilities can be added using `capabilities.add`
