<!-- Installation Packages -->
pip install fastapi
pip install uvicorn


<!-- Uvicorn - uvicorn is a server where our fastapi will expose ml api's -->

uvicorn main:app --reload
<!-- --reload helps in hot reload -->

<!-- For Testing of the API for the Frontend Developers -->
/doc
/redoc

Advantage of FastAPI over Flask

1) Inbuild Data Validation
2) Inbuild Documentation Support/Testing of the API using [/doc,/redoc]
3) FastAPI is very fast 
4) Code is reusable and easy to understand