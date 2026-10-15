#!/bin/bash
set -euo pipefail

# Generates a self-signed certificate + private key for local HTTPS development.
# Do NOT use the generated files in production, use a certificate from a real CA instead.
#
# Usage: make-dev-cert.sh [output-dir] [hostname] [days]
# Defaults: output-dir=./certs, hostname=localhost, days=365

OUT_DIR="${1:-./certs}"
HOST="${2:-localhost}"
DAYS="${3:-365}"

if ! command -v openssl >/dev/null 2>&1; then
  echo "openssl not found. Install it first (e.g. sudo apt-get install openssl)." >&2
  exit 1
fi

CRT_FILE="$OUT_DIR/localhost.crt"
KEY_FILE="$OUT_DIR/localhost.key"

if [[ -e "$CRT_FILE" || -e "$KEY_FILE" ]]; then
  echo "Refusing to overwrite existing files: $CRT_FILE $KEY_FILE" >&2
  exit 1
fi

mkdir -p "$OUT_DIR"

openssl req -x509 -newkey rsa:2048 -nodes \
  -keyout "$KEY_FILE" \
  -out "$CRT_FILE" \
  -days "$DAYS" \
  -subj "/CN=$HOST" \
  -addext "subjectAltName=DNS:$HOST,IP:127.0.0.1"

chmod 600 "$KEY_FILE"

echo "Wrote $CRT_FILE and $KEY_FILE (dev only, self-signed for $HOST)."
