Get http://localhost:3000/api/products
Accept: application/json

{%
    client.test("GET http://localhost:3000/api/products", function() {
        client.assert(response.body == "Hello, Deno!!", "The ")
    })
}