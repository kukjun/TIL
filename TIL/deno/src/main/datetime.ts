import { dayOfYear, currentDayOfYear } from "https://deno.land/std/datetime/mod.ts";

console.log(dayOfYear(new Date("2020-07-01")));
console.log(currentDayOfYear())