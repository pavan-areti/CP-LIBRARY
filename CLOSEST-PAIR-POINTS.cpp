// list of points -> {closest pair (squared) distance, {point1, point2}}
pair<int, pair<pii, pii>> closest_pair(vec<pii> pts) {
    int n = sz(pts);
    sort(all(pts));
    set<pii> s;

    pair<int, pair<pii, pii>> best_dist = {LLONG_MAX, {{-1, -1}, {-1, -1}}};
    int j = 0;
    for(int i = 0; i < n; ++i) {
        int d = ceil(sqrt(best_dist.ff));
        while(j < n and pts[i].ff - pts[j].ff >= d) {
            s.erase({pts[j].ss, pts[j].ff});
            ++j;
        }

        auto it1 = s.lb({pts[i].ss - d, pts[i].ff});
        auto it2 = s.ub({pts[i].ss + d, pts[i].ff});
        
        for(auto it = it1; it != it2; ++it) {
            int dx = pts[i].ff - it->second;
            int dy = pts[i].ss - it->first;
            best_dist = min(best_dist, {dx * dx + dy * dy, {{it->ss, it->ff}, pts[i]}});      
        } 
        s.insert({pts[i].ss, pts[i].ff}); 
    }
    return best_dist;
}
