## Building Environment

For reproductive experiments, we recommend you to use the dockers we prepared:

Ubuntu 18.04 Docker:

```
$ root@compiler:/CISB-dataset/reproduction # docker build -t cisb .
$ root@compiler:/CISB-dataset/reproduction # docker run -itd --name dataset --privileged cisb
```

And if you want to run overhead reproductive experiments, and want to use your own SPEC CPU2006 environment. We recommend you to mount a host directory which contains SPEC CPU2006 to the docker. Use the following instructions instead.

```
$ root@compiler:/CISB-dataset/reproduction # docker build -t cisb .
$ root@compiler:/CISB-dataset/reproduction # docker run -itd -v /the/path/to/spec_cpu2006/:/cisb_docker/spec/cpu2006 --name dataset --privileged cisb
```

Run the following instructions to get into the docker:

```
$ root@compiler:/CISB-dataset/reproduction # docker exec -it dataset /bin/bash
```

Finally, to reproduce, To reproduce, please follow the instructions [here](https://github.com/linkeLi0421/CISB-dataset/tree/main/reproduction)