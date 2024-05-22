/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include<stdio.h>
#include<stdlib.h>
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  /* Start engine. */
  /*ADD begin*/
  FILE *file;
  char line[1024];  //假设每行不超过1024个字符，加上一个'\0'字符作为结束符
  file=fopen("../tools/gen-expr/input","r");
  if(file==NULL){
    perror("Error opening file");
    return 1;
  }
  // 读取文件的每一行，直到EOF（文件末尾）  
    while (fgets(line, sizeof(line), file) != NULL) {  
        // 输出读取到的行  
        printf("%s", line);  
    }  
  /*ADD end*/
  engine_start();

  return 0;
}
