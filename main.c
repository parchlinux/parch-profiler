#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* profiles[] = {
  "gaming", "/usr/share/parch-profiles/gaming",
  "development", "/usr/share/parch-profiles/development"
};

void apply(const char* profile) {
  char cmd[1024];
  sprintf(cmd, "cat %s | xargs -d '\\n' paru -S --noconfirm", profile);
  system(cmd);
}

void rm(const char* profile) {
  char cmd[1024];
  sprintf(cmd, "cat %s | xargs -d '\\n' paru -Rds --noconfirm", profile);
  system(cmd);
}

void sideload_apply(const char* file) {
  char cmd[1024];
  sprintf(cmd, "cat %s | xargs -d '\\n' paru -S --noconfirm", file);
  system(cmd);
}

void sideload_rm(const char* file) {
  char cmd[1024];
  sprintf(cmd, "cat %s | xargs -d '\\n' paru -Rds --noconfirm", file);
  system(cmd);
}

void list() {
  int i;
  printf("Available profiles:\n");
  for (i = 0; i < sizeof(profiles)/sizeof(profiles[0]); i+= 2) {
    printf("%s\n", profiles[i]);
  }
}

void test() {
  printf("Hello, i am Parch Profiler written in C :D\n");
}

int main(int argc, char** argv) {

  if (argc < 2) {
    printf("Usage: parch-profile [apply|rm|sideload-apply|sideload-rm|test] [args]\n");
    return 1;
  }

  char* action = argv[1];
  char* profile;

  if (argc > 2) {
    profile = argv[2];
  } else {
    printf("Enter profile: ");
    scanf("%s", profile);
  }

  if (strcmp(action, "apply") == 0) {
    apply(profile);
  } else if (strcmp(action, "rm") == 0) {
    rm(profile);
  } else if (strcmp(action, "sideload-apply") == 0) {
    sideload_apply(argv[2]);
  } else if (strcmp(action, "sideload-rm") == 0) {
    sideload_rm(argv[2]);
  } else if (strcmp(action, "test") == 0) {
    test();
  } else if (strcmp(action, "list") == 0) {
    list();
  } else {
    printf("Usage: parch-profile [apply|rm|sideload-apply|sideload-rm|test] [args]\n");
    return 1;
  }

  return 0;
}
