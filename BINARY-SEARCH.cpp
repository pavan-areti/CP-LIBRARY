int start = , end = , ans = -1;
while(start <= end) {
    int mid = start + (end - start) / 2;
    if(chk(mid)) {
        ans = mid;
        start = mid + 1;
    }
    else {
        end = mid - 1;
    }
}
