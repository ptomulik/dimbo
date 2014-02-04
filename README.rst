DIMBO website
=============

This is website project for DIMBO project. It's based on jekyll_ blog-aware
templating engine.

Tips for developers
-------------------

Install bundler first (if you don't have one):

.. code:: bash

    apt-get install bundler

Install all gems necessary to run jekyll_

.. code:: bash

    bundle install --path vendor/bundle

Start jekyll_ server

.. code:: bash

    bundle exec jekyll serve --watch --baseurl ''

Open your browser and go to your website: ``http://localhost:4000/``

    

.. _jekyll: http://jekyllrb.com/
