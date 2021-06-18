#!/usr/bin/bash
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 username@asgard_ip /path/to/file.elf" >&2
  exit 1
fi

set +x;
set +v;

/usr/bin/expect -c '
log_user 0
spawn scp '$2' "'$1':/tmp/debug.elf"
expect "password"
send "ubuntu\n"
log_user 1
expect eof'