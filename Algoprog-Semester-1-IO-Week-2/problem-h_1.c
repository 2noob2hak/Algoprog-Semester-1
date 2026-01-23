#include <stdio.h>

int main(void) {
	char s[100];
	scanf("%[^\n]", s);
	printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\",\"%s\");\n", s);
    printf("    return 0;\n");
    printf("}\n");
	return 0;
}
