
## Prometheus server 

1. Retrivial :pull service data 
2. Storage : stores metric data 
3. HTTP server: accepts queries
## Target and Metrics 

- Servers 
- application 
- database

What units are monitored of those targets?
- CPU status
- Memory disk 
- Requests 


## Metrics 

- Metrics entries: TYPE and HELP attributes
- HELP: description of what the metric is 
- TYPE: 3 types 
1. Counter type: how many times X happend? 
2. Gauge: what is the current value of X now? 
3. Histogram: how big of a request incoming? 


## How prometheus pull metrics data from target? 

- Data is pulled from the HTTP endpoints, must be in the format the prometheus understands
- For some endpoints, metrics are available by default
- For some others: the **exporter** (e.g: Elastic search) fetches the metric from the target, convert the metric to the correct format, then expose the metric so that prometheus can scrape them. We then will have to configure prometheus to scrape those endpoints.
## Metrics 

### Gauges 
- Metrics that can go up or down: current measurement 
- Set(), Inc(), Dec()
### Counter
- Cumulative counts overtime 
- Counter only go up, unless crash
- Inc(), Add()
- PromQL: rate(), irate(), increase()
### Summaries
- Distribution of request latency or set of numeric values
-



## Prometheus operator 

1.  Custom resources: 
- Alert Manager
- Prometheus rule
- Alertmanger config
- service monitor
- pod monitor


### Exporter

3 components: 
- Exporter application (mongodb image instance in a pod)
- Service 
- ServiceMonitor : P must know about the endpoint ready to be scraped 

`helm show values prometheus-community/prometheus-mongodb-exporter > values.yaml`

-> command to make edit to the exporter


after making edit, run

`helm install mongodb-exporter prometheus-community/prometheus-mongodb-exporter -f values.yaml`