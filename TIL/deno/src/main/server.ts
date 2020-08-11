import { Application, Router } from "https://deno.land/x/oak/mod.ts";

const port = 3000;
const app = new Application();
const router = new Router();

app.use(router.routes());
app.use(router.allowedMethods());

router.get("/api/products", ({ response }: { response: any }) => {
    response.body = "Hello, Deno!!";
});

console.log('The server running on port &{port}.');
await app.listen({ port });