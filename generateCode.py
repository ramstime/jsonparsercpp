#!/usr/bin/env python
import os
import sys
import argparse

def main():

   parser = argparse.ArgumentParser(description='To parse the arguments')
   parser.add_argument('--jsonpath',help='json def dir path', required=True)
   parser.add_argument('--stjsonpath',help='static json repo path', required=True)
   parser.add_argument('--incpath',help='include path for generated files', required=True)
   args = parser.parse_args()

   #if args.jsonpath is None:
   #   print("path not passed")
   #jsonpath = args.jsonpath # sys.argv[1]
   """
   cwd = os.getcwd()
   json_path = cwd+"/"+args.jsonpath
   #inc_path = jsonpath.split("/")
   #print("inc_path:", inc_path)
   #del token_path[-3:] 
   #inc_path = "/".join(inc_path) + "/inc/"
   inc_path = cwd+"/"+ args.incpath
   print("inc_path:", inc_path)
   #os.chdir(path)
   """
   for file in os.listdir(args.jsonpath):
       if file.endswith(".json"):
          print("file:", file)
          file_name,ext = file.split('.')
          file_name = file_name[:-4]
          print("file_name :",file_name)
          file_header = args.incpath + file_name + ".h"
          command = "python {stjson_path}/autojsoncxx/autojsoncxx.py --input={json_path}/{def_json} --output={file_header}".format(
          def_json=file,
          json_path=args.jsonpath,
          file_header=file_header,
          stjson_path=args.stjsonpath
          )
          print("executing command:",command)
          os.system(command)
          astyle="astyle {file_header}".format(file_header = file_header)
          print("executing astyle:", astyle)
          os.system(astyle)
          file_header=file_header +".orig"
          os.system("rm {file_header}".format(file_header = file_header))
       elif file.endswith(".py"):
          print()
       else:
          print("only json def files should be present in this dir")
       # for file in files:
       # print(file)
   print("all done")

main()


