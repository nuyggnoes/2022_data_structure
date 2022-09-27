sscanf(line, "%[^,], %d", name, &number);
printf("%-6s %-20s", "Name: ", name);
printf("%10s %-12d\n", "Number: ", number);