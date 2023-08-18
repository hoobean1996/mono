# Princinple

Consider a large scale distributed system with many instances, what is requried?

1. As a client, it must have the ability to communicate with every instance, so we have to integrate RoutingCli for every generic client.

2. So client can have this kind of API

```c++
// client
class Client {
  Result store(std::string_view key, char[] value);
};

int main() {
  cli := ClientFactory::for("store_service")
  cli.store(key, value, shard_id); // by default, shard_id is decided by server
  return 0;
}
```

2. As a server, it must have the ability to scale, it can integreate with Kubernetes/Twine like system.

```c++
  status add_shard(shard_id);
  status drop_shard(shard_id);
  status change_role(shard_id, primary -> secondary);
  status update_membership(shard_id, [m1, m2, ....])
```

# gRPC

For go gRPC, every time we updated the proto files, we need to manually copy the generated files to our project.

## RoutingD

RoutingD is a general serive discovery service. It provides several features as below:

1. Service Register: when a new service bootstrap, the service needs to register itself to the RoutingD, then the cilents can communicate with it.
2. Service Discovery: when a client needs to communicate with service, it have to look up an available service from the RoutingD, and then start to communicate with it.

### Exceptions

1. If a service already down, how could we find it
2. If a service is pasued, for example like GC, how could we tolerate it

### CP or AP

CAP is a theory in distributed system, it means Consistency, Avaialability and Partition Tolerance, you can achieve at most two.
P is always required, so we have to take trade off between Consistency and Availability.

Routing service can be build as CP or AP, it depends on your use case.

- ZooKeeper, Etcsd, Consul: CP
- Eureka: Ap
