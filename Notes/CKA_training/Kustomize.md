  Goal: reuse kubernetes config and only modify what needs to be changed 
  `apiVersion: kustomize.config.k8s.io/v1beta1`
  - Base: config that is identical across environment, default values
  - Overlay: customize behavior for each environment

 ![](../../img/Pasted%20image%2020250629184433.png)
## Kustomize folder structure

![](../../img/Pasted%20image%2020250629184547.png) 
## Kustomize vs.  Helm

![](../../img/Pasted%20image%2020250629185259.png)

## Kustomization.yaml file 
1. `resources`
	- Specify yaml file which kustomize needs to keep track of 
 2. Customizations that need to be made
![](../../img/Pasted%20image%2020250629185645.png)

## Build

```bash
kustomize build <directory-where-kustomize-is>
```

- At the build time, kustomize will look at kustomization.yaml, build all the resources listed and apply appropriate customizations, but **doesn't apply or deploy** the Kubernetes resources to the cluster.

![](../../img/Pasted%20image%2020250629185913.png)

## Kustomize Output
- To apply output
```bash
kustomize build k8s/ | kubectl delete -f - 
kustomize build -k k8s/ 
```
- To delete output:
```bash
kustomize build k9s/ | kubectl delete -f - 
kustomize build -k k9s/ 
```
## Managing Directories 

### method 1: kustomization at root
![](../../img/Pasted%20image%2020250629190937.png)
- At the root directory, apply kustomize at the root directory 
### method 2: kustomization in subfolder

![](../../img/Pasted%20image%2020250629191147.png)

## Common Transformer

![](../../img/Pasted%20image%2020250629192012.png)

### Image Transformer 
1. Change the name of the `image`
![](../../img/Pasted%20image%2020250629203702.png)

2. Change tag 
![](../../img/Pasted%20image%2020250629203745.png)
3. Both tag and image can be specified to be changed together


## Patch
- Target 1 or more specific sections in a Kubernetes resources
- To create a patch, 3 params must be provided:
	1. Operation types: add/remove/replace
	2. Target: what resources should this patch be applied on?
	3. Value
### Example 1 (Json 6902)
![](../../img/Pasted%20image%2020250629211410.png)
### Example 2 (Json 6902)

![](../../img/Pasted%20image%2020250629211548.png)

### Inline vs Separate File

1. Json 6902: inline vs separate file
![](../../img/Pasted%20image%2020250629213652.png)
2. Strategic merge:  inline vs separate file
![](../../img/Pasted%20image%2020250629213842.png)

## Patches Dictionary
### Replace
1. Json6902: provide the path to the field needed to be changed
![](../../img/Pasted%20image%2020250630212456.png)
2. Strategic Merge: take the same template (i.e: deployment template) over, change only what needed to be changed
![](../../img/Pasted%20image%2020250630212649.png)

### Add Dictionary 
1. json6902: provide path to the new key, and the value
![](../../img/Pasted%20image%2020250630212906.png)
2. strategic merge : kustomize will merge new key:value with old one
![](../../img/Pasted%20image%2020250630213007.png)

### Remove Dictionary 
1. Json6902
![](../../img/Pasted%20image%2020250630213122.png)
2. Strategic merge patch: set `key` to `null`
![](../../img/Pasted%20image%2020250630213147.png)

## Patches List

### Replace
1. Json6902: index is appended at the end of link
![](../../img/Pasted%20image%2020250630213625.png)
2.  Strategic merge patch: specify same key:value within the list
![](../../img/Pasted%20image%2020250630213826.png)

### Add List
1. Json6902: add could add to an index (i.e.:0,1,2) or `-` means appending to end of list
![](../../img/Pasted%20image%2020250630214255.png)
2. Strategic Merge: specify the item wanted to add
![](../../img/Pasted%20image%2020250630214412.png)

### Delete List
1. Json 
![](../../img/Pasted%20image%2020250630214521.png)
2. Strategic merge path: use the `$patch:delete` directive
![](../../img/Pasted%20image%2020250630214601.png)

## Overlays

- Change the existing config: i.e. Base has 1 replicas, change it to 2 for dev
![](../../img/Pasted%20image%2020250630215110.png)

- Customize config that's different from the base 
![](../../img/Pasted%20image%2020250630215358.png)

>[!Note] kustomization.yaml in subfolder and base folder don't necessarily needs to depend on each other. They can but don't have to. 

![](../../img/Pasted%20image%2020250630215548.png)

## Components
- Define reusable pieces of configuration logic (resources + patches) that can be included in multiple overlays -> helpful with features that needs to be enabled only in a subset of overlays
![](../../img/Pasted%20image%2020250701085638.png)

### Dir structure 
1. db/kustomization.yaml  
![](../../img/Pasted%20image%2020250701085855.png)
2. db/deployment-patch.yaml
![](../../img/Pasted%20image%2020250701090505.png)
3. db/postgres-depl.yaml
![](../../img/Pasted%20image%2020250701090740.png)

### Include components 
![](../../img/Pasted%20image%2020250701101119.png)
