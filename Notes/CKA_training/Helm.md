- Package Manager for Kubernetes 
- To Install/uninstall
```bash
helm install/uninstall <name-o-chart>
```
- To upgradeL
```bash
helm upgrade <name-o-chart>
```
- To rollback:
```bash
helm rollback <name-o-chart>
```

## Note on helm 2 vs helm 3
- Tilt: is removed in helm 2 as RBAC is taking charge
- 3-way-strategic-merge-patch: taking live-stage version into consideration in rollback or upgrade. 
## Helm components
- `values.yaml` is the input file that can be customized 
- Releases name: is a customized name that we can give to the chard on `install`. Especially useful when having multiple instances of a chart to test.

## Helm Charts 
1. Template directory
	- service.yaml, pods.yaml, deployment.yaml 
2. Values.yaml 
	- Contains values to fill in the template 
3. Chart.yaml 
	 - Contains information about the chart itself.  
4. LICENSE
	 - Chart's license info
5. README.md
6. charts
	  - Dependency charts
## About Chart.yaml
- `apiVersion:v2` new for helm 3
- `appVersion`: version of the app in the helm chart
- `version`: version of the chart itself 
- `type`: application or library
	- application: default, to create application
	- library: utilities in helping building chart
- `dependencies`: any dependencies that this Helm chart needs
- `keywords`: can be helpful when searching for chart in a public chart's repository
- `maintainer`: info about maintainers

## Searching for hub/repo 

```bash
helm search <name-of-chart>
helm search hub <name>
helm search repo <name>
```

## Custom params for values
1. Using `--set`(can be used multiple times): `helm install --set myCustomname="somename" my-release bitnami/wordpress`
2. Using `--value` :`helm install --values custom-values.yaml my-release bitnami/wordpress`
3. Using `Helm pull`:
	1.  helm pull --untar bitnami/wordpress
	2. ls ---> wordpress dir 
	3. helm install my-release ./wordpress
![](../../img/Pasted%20image%2020250629214847.png)

## Life cycle management with Helm
- A chart can be installed as independent releases 
### Upgrade

```bash 
helm upgrade nginx-release bitnami/nginx
```

- To get history:
```bash
helm history nginx-release
```

### Rollback 

```bash
helm rollback nginx-release <revision-number>
```

- Rollback creates a new version 


