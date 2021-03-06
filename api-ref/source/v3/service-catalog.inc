.. -*- rst -*-

===============================
 Service catalog and endpoints
===============================

A service is an OpenStack web service that you can access through a
URL, or endpoint.

A service catalog lists the services that are available to the
caller based upon the current authorization.

You can create, list, show details for, update, and delete
services. When you create or update a service, you can enable the
service, which causes it and its endpoints to appear in the service
catalog.

You can create, list, show details for, update, and delete
endpoints.


List services
=============

.. rest_method::  GET /v3/services

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/services``

Lists all services.

Normal response codes: 200
Error response codes: 413,405,404,403,401,400,503

Request
-------

.. rest_parameters:: parameters.yaml

   - type: service_type_query

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - name: service_name
   - links: service_links
   - enabled: service_enabled
   - services: services
   - type: service_type
   - id: service_id
   - description: service_description

Response Example
----------------

.. literalinclude:: ./samples/admin/services-list-response.json
   :language: javascript


Create service
==============

.. rest_method::  POST /v3/services

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/services``

Creates a service.

Normal response codes: 201
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - description: service_description
   - service: service
   - enabled: service_enabled
   - service_id: service_id
   - type: service_type
   - name: service_name

Request Example
---------------

.. literalinclude:: ./samples/admin/service-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - name: service_name
   - service: service
   - links: service_links
   - type: service_type
   - id: service_id
   - description: service_description


Show endpoint details
=====================

.. rest_method::  GET /v3/endpoints/{endpoint_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/endpoints``

Shows details for an endpoint.

Normal response codes: 200
Error response codes: 413,405,404,403,401,400,503

Request
-------

.. rest_parameters:: parameters.yaml

   - endpoint_id: endpoint_id_path

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - endpoint: endpoint
   - name: endpoint_name
   - links: endpoint_links
   - url: endpoint_url
   - region: endpoint_region
   - interface: endpoint_interface
   - service_id: service_id

Response Example
----------------

.. literalinclude:: ./samples/admin/endpoint-show-response.json
   :language: javascript


Update endpoint
===============

.. rest_method::  PATCH /v3/endpoints/{endpoint_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/endpoint``

Updates an endpoint.

Normal response codes: 200
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - endpoint: endpoint
   - url: endpoint_url
   - region: endpoint_region
   - interface: endpoint_interface
   - service_id: service_id
   - endpoint_id: endpoint_id_path

Request Example
---------------

.. literalinclude:: ./samples/admin/endpoint-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - endpoint: endpoint
   - id: endpoint_id
   - links: endpoint_links
   - url: endpoint_url
   - region: endpoint_region
   - interface: endpoint_interface
   - service_id: service_id

Response Example
----------------

.. literalinclude:: ./samples/admin/endpoint-update-response.json
   :language: javascript


Delete endpoint
===============

.. rest_method::  DELETE /v3/endpoints/{endpoint_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/endpoint``

Deletes an endpoint.

Normal response codes: 204
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - endpoint_id: endpoint_id_path


List endpoints
==============

.. rest_method::  GET /v3/endpoints

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/endpoints``

Lists all available endpoints.

Normal response codes: 200
Error response codes: 413,405,404,403,401,400,503

Request
-------

.. rest_parameters:: parameters.yaml

   - interface: interface_query
   - service_id: service_id_query

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - region_id: region_id
   - links: endpoints_links
   - url: endpoint_url
   - region: endpoint_region
   - enabled: endpoint_enabled
   - interface: endpoint_region
   - service_id: service_id
   - endpoints: endpoints
   - id: endpoint_id

Response Example
----------------

.. literalinclude:: ./samples/admin/endpoints-list-response.json
   :language: javascript


Create endpoint
===============

.. rest_method::  POST /v3/endpoints

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/endpoints``

Creates an endpoint.

Normal response codes: 201
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - endpoint: endpoint
   - url: endpoint_url
   - enabled: endpoint_enabled_notRequired
   - interface: endpoint_interface
   - service_id: service_id
   - region_id: region_id

Request Example
---------------

.. literalinclude:: ./samples/admin/endpoint-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - endpoint: endpoint
   - links: endpoint_links
   - url: endpoint_url
   - region: endpoint_region
   - enabled: endpoint_enabled
   - interface: endpoint_interface
   - service_id: service_id
   - id: endpoint_id
   - region_id: region_id


Show service details
====================

.. rest_method::  GET /v3/services/{service_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/service``

Shows details for a service.

Normal response codes: 200
Error response codes: 413,405,404,403,401,400,503

Request
-------

.. rest_parameters:: parameters.yaml

   - service_id: service_id_path

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - name: service_name
   - service: service
   - links: service_links
   - type: service_type
   - id: service_id
   - description: service_description

Response Example
----------------

.. literalinclude:: ./samples/admin/service-show-response.json
   :language: javascript


Update service
==============

.. rest_method::  PATCH /v3/services/{service_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/services``

Updates a service.

The request body is the same as the create service request body,
except that you include only those attributes that you want to
update.

Normal response codes: 200
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - type: service_type
   - enabled: service_enabled
   - description: service_description
   - service: service
   - name: service_name
   - service_id: service_id_path

Request Example
---------------

.. literalinclude:: ./samples/admin/service-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - name: service_name
   - service: service
   - links: service_links
   - type: service_type
   - id: service_id
   - description: service_description

Response Example
----------------

.. literalinclude:: ./samples/admin/service-update-response.json
   :language: javascript


Delete service
==============

.. rest_method::  DELETE /v3/services/{service_id}

Relationship: ``http://docs.openstack.org/api/openstack-identity/3/rel/service``

Deletes a service.

If you try to delete a service that still has associated endpoints,
this call either deletes all associated endpoints or fails until
all endpoints are deleted.

Normal response codes: 204
Error response codes: 413,415,405,404,403,401,400,503,409

Request
-------

.. rest_parameters:: parameters.yaml

   - service_id: service_id_path
