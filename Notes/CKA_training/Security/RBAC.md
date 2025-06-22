1. Create role object, with name, specify set of rules:
	- For CORE group: `apiGroups` can be left blank 
	- Multiple rules can be created for a single role
2. Link User to the Role
	1.  Create RoleBinding: link user obj to a role
>[!Important] 
>`Role` and `RoleBinding` are namespaced. 

![](../../../img/Pasted%20image%2020250608193810.png)
- If wanting to limit access to Namespace, specify namespace under `metadata`

## Check acess

```bash 
kubectl auth can-i create deployments
```

- Impersonate :
```
kubectl auth can-i create pods --as dev-user --namespace test
```

- Use `resourceName` under `rules` in `Role` object to restrict access only to those specifief resources: 
![](../../../img/Pasted%20image%2020250608194309.png)


## Role and RoleBinding
- Namespaced 
- To check if a resources is namespaced or not:
```bash 
	kubectl api-resource --namespaced=true
```

## ClusterRole 

![](../../../img/Pasted%20image%2020250610162824.png)
- We can create CluterRole within a specific namespace