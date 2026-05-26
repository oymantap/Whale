#!/bin/bash
echo "Melakukan kompilasi..."
if make; then
    echo "Kompilasi sukses! Menginstall ke sistem..."
    cp whale /data/data/com.termux/files/usr/bin/
    echo "Whale berhasil diinstall!"
else
    echo "Gagal kompilasi. Cek kode kamu dulu!"
fi

