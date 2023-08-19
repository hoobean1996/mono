import { useEffect, useState } from "react";
import { InternalRouteMap } from "./InternalRouteMap";
import { InternalRouteMapContext } from "./InternalRouteMapContext";
import { InternalRouter } from "./InternalRouter";

type Props = {};

export function InternalRoot({}: Props) {
  const [currentPath, setCurrentPath] = useState<string>(
    window.location.pathname
  );
  useEffect(() => {
    const onLocationChange = () => {
      setCurrentPath(window.location.pathname);
    };
    window.addEventListener("navigate", onLocationChange);
    return () => window.removeEventListener("navigate", onLocationChange);
  }, []);
  return (
    <InternalRouteMapContext.Provider value={InternalRouteMap}>
      <InternalRouter path={currentPath} />
    </InternalRouteMapContext.Provider>
  );
}
