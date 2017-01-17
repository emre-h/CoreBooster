ultra() {
    echo performance | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor > /dev/null
}

normal() {
    echo powersave | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor > /dev/null
}

if [ "$EUID" -ne 0 ]; then¬                                                                                
    echo "Bu programı çalıştırabilmek için root olmalısınız." >&2
    exit 1
fi

read -p "Normal mi olsun Ultra mı?" -i "N/U" -e tip

if [[ $tip =~ [Nn].* ]]; then
    normal
elif [[ $tip =~ [Uu].* ]]; then
    ultra
else
    echo "Hatalı giriş." >&2
fi
