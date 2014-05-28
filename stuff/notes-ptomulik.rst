NOTES
=====

This is a board with yellow sticks. Whenever I find an information I think it
may be usefull in near future, I put it here.

CONTENTS
--------

1. `GPU related notes`_


.. _GPU related notes:
GPU related notes
^^^^^^^^^^^^^^^^^

How to hide some CUDA devices from an application
`````````````````````````````````````````````````

Use ``CUDA_VISIBLE_DEVICES``, see `this article <https://devblogs.nvidia.com/parallelforall/cuda-pro-tip-control-gpu-visibility-cuda_visible_devices/>`_ and `this blog post <http://acceleware.com/blog/cudavisibledevices-masking-gpus>`_.

CUDA Environment variables
``````````````````````````

There is a bunch of environment variables which affect CUDA drivers, see `the documentation <http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#env-vars>`_.
