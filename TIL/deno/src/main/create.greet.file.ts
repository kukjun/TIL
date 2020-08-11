const encoder = new TextEncoder();
const greetText = encoder.encode("Hello, Deno\nMy name is Kukjun.");

await Deno.writeFile("../resourse/output/greet.txt", greetText);