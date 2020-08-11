const file = await Deno.open("../resourse/output/greet.txt");
await Deno.copy(file, Deno.stdout);
file.close();