2 types of accounts: 
- Service Account: used by application to interact with application (i.e: prometheus, jenkins)
- User Account: admin, developer 
## Create a SA 
```bash
	kubectl create serviceaccount <name>
```
- A token will be auto created with the SA: the token is created as secret object, which linked to 

## Default SA 
- Whenever there is a new namespace created, a service account named `default` is auto created. 
- When a pod is created within that namespace, the SA is mounted into the pod. 
- SA only has permission to run basic API query
- SA can be specified under pods.spec with `serviceAccountName` 
- SA can't be editted from an existing pod. Pod must be deleted and recreated
- SA can be updated in deployment, however. 
- `automountServiceAccountToken`: set to `false` if not desired for auto SA mounting 
## New update for 1.22 
- SA with jwt without any timebound is no longer used. Instead, a token with a defined lifetime is generated thru the token-request api by the service account admission controller when the pod is created 
## New update for 1.24
- Token is no longer created after service account is created 