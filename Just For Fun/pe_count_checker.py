# -*- coding: utf-8 -*-
# 가나다라

import pefile
import time


class Counter:

    def count_files(self, path_list):
        print("Path List: ", path_list)
        start_time = time.time()

        # Set Counting Conditions
        excludes = settings.EXCLUDE_OR_RESTRICTION_RULES["Exclude_path"]
        include_extension = settings.EXCLUDE_OR_RESTRICTION_RULES["Include_Extension"]
        max_size = settings.EXCLUDE_OR_RESTRICTION_RULES["Maximum_Size"]
        collect_pe = settings.EXCLUDE_OR_RESTRICTION_RULES["Collect_PE"]
        file_info_list = []

        include_extension = r'|'.join([fnmatch.translate(x) for x in include_extension])
        if exclude_extension:
            exclude_extension = r'|'.join([fnmatch.translate(x) for x in exclude_extension])
        excludes = r'|'.join([fnmatch.translate(x) for x in excludes]) or

        detect_file_count = 0

        for path in path_list:
            print("=" * 80)
            print("PATH: ", path)
            print("=" * 80)

            for root, dirs, files in os.walk(path):
h

def is_pe(file_path):
    count = 0
    if type(file_path) is list:
        for path in file_path:
            pass
    else:
        try:
            pe = pefile.PE(file_path)
            count += 1
        except Exception as e:
            print("PE Check Error::" + str(e))
            pass

def main():
    pass

if __name__ == '__main__':
    main()
