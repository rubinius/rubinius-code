__dir__="$(cd "$(dirname "$0")" && pwd)"

function rbx_codetools_cache_name {
  echo "rubinius-codetools-cache.bz2"
}

function rbx_binary_bucket {
  echo "rubinius-binaries-rubinius-com"
}

function rbx_url_prefix {
  local bucket=$1
  echo "https://${bucket}.s3-us-west-2.amazonaws.com"
}
